#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>
#include <map>
#include <unordered_set>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int data_pass)
    {
        data = data_pass;
        right = nullptr;
        left = nullptr;
    }
    ~node()
    {
        // cout << "destructor \n";
        delete (this->left);
        delete (this->right);
    }
};
node *create_new_node(int data)
{
    node *return_node = new node(data);
    if (return_node)
    {
        return return_node;
    }
    assert(0);
}
void add_node(node *root, vector<int> value, vector<char> direction)
{
    assert(root != nullptr);
    node *temp = root;
    for (int i = 0; i < direction.size(); ++i)
    {
        if (direction[i] == 'L')
        {
            if (temp->left)
            {
                //
                // check for input
                //
                if (temp->left->data != value[i])
                {
                    cout << "Invalid input for L " << value[i] << "\n";
                    return;
                }
            }
            else
            {
                //
                // create a new node
                //
                temp->left = create_new_node(value[i]);
                cout << "added on L " << temp->left->data << "\n";
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right)
            {
                //
                // check for input
                //
                if (temp->right->data != value[i])
                {
                    cout << "Invalid input for R " << value[i] << "\n";
                    return;
                }
            }
            else
            {
                //
                // create a new node
                //
                temp->right = create_new_node(value[i]);
                cout << "added on R " << temp->right->data << "\n";
            }
            temp = temp->right;
        }
    }
}
void print_tree(node *root)
{
    if (root == nullptr)
        return;

    print_tree(root->left);
    cout << root->data << " ";
    print_tree(root->right);
}
int tree_max(node *root)
{
    static int ans = INT8_MIN;
    if (root)
    {
        ans = max(root->data, ans);
        tree_max(root->left);
        tree_max(root->right);
    }
    return ans;
}
int tree_height(node *root)
{
    if (!root || (!root->left && !root->right))
        return 0;
    return (max(tree_height(root->left), tree_height(root->right))) + 1;
}
int tree_count_node(node *root)
{
    if (root == nullptr)
        return 0;
    return (tree_count_node(root->left) + tree_count_node(root->right)) + 1;
}
int tree_count_leaf(node *root)
{
    static int count = 0;
    if (root == nullptr)
        return 0;
    if (!root->left && !root->right)
        count++;
    tree_count_leaf(root->left);
    tree_count_leaf(root->right);
    return count;
}
bool tree_element_exist(node *root, int value)
{
    if (root == nullptr)
        return false;
    if (root->data == value)
    {
        return true;
    }
    return (tree_element_exist(root->left, value) || tree_element_exist(root->right, value));
}
bool tree_perfect(node *root)
{
    if (root == nullptr)
        return false;

    if (root->left == nullptr && root->right == nullptr)
        return true;

    if ((root->left && root->right))
        return (tree_perfect(root->left) && tree_perfect(root->right));

    return false;
}
bool tree_leaf_node(node *node)
{
    if (node)
    {
        return (node->right == nullptr && node->left == nullptr);
    }
    return false;
}
void mark_visited(node *child, unordered_set<node *> &m)
{
    m.insert(child);
}
bool all_children_visited(node *root, unordered_set<node *> &m)
{
    //
    // left && right NUll is already checked
    //
    if (root->left == nullptr && (m.find(root->right) != m.end()))
    {
        return true;
    }
    else if (root->right == nullptr && (m.find(root->left) != m.end()))
    {
        return true;
    }
    else if ((m.find(root->left) != m.end()) && (m.find(root->right) != m.end()))
    {
        return true;
    }
    return false;
}
bool leaf_node(node *root)
{
    if (root->right == nullptr && root->left == nullptr)
    {
        return true;
    }
    return false;
}

void tree_inorder_iter(node *root)
{
    //
    // init code
    //
    stack<node *> s;
    unordered_set<node *> m;

    //
    // step:1 - put left and right child into
    // the stack the mark them visited
    //

    if (root->right)
    {
        s.push(root->right);
        mark_visited(root->right, m);
    }
    s.push(root);
    mark_visited(root, m);

    if (root->left)
    {
        s.push(root->left);
        mark_visited(root->left, m);
    }

    //
    // step2: parse the stack
    //        2.1 - pop the element check if this is leaf node ||
    //              all the children of the node is visisted.
    //              if(yes) -> then print the element
    //              else -> put the right child of the node into the element
    //                      put the node into the elemnt
    //                      put left child into the element.
    // step 3: pop the element and process with step: 2
    //
    while (!s.empty())
    {
        node *temp = s.top();
        // cout << "popped " << temp->data << "\n ";
        s.pop();

        if (leaf_node(temp) || all_children_visited(temp, m))
        {
            cout << temp->data << " ";
        }
        else
        {
            if (temp->right)
            {
                s.push(temp->right);
                mark_visited(temp->right, m);
            }

            s.push(temp);
            mark_visited(temp, m);

            if (temp->left)
            {
                s.push(temp->left);
                mark_visited(temp->left, m);
            }
        }
    }
    cout << endl;
}
void tree_spiral_traversal(node *root)
{
    //
    // init code
    //
    stack<node *> s1; // right and then left
    stack<node *> s2; // left and then right
    // map<node *, bool> m;
    unordered_set<node *> us;

    //
    // step:1 - put left and right child into
    // the stack the mark them visited
    //
    if (root->right)
    {
        s1.push(root->right);
        mark_visited(root->right, us);
    }

    if (root->left)
    {
        s1.push(root->left);
        mark_visited(root->left, us);
    }
    s1.push(root);
    mark_visited(root, us);

    //
    // step2: parse the stack
    //        2.1 - pop the element check if this is leaf node ||
    //              all the children of the node is visisted.
    //              if(yes) -> then print the element
    //              else -> put the right child of the node into the element
    //                      put the node into the elemnt
    //                      put left child into the element.
    // step 3: pop the element and process with step: 2
    //
    while (!s1.empty() && !s1.empty())
    {
        while (!s1.empty())
        {
            node *temp = s1.top();
            // cout << "popped " << temp->data << "\n ";
            s1.pop();

            if (leaf_node(temp) || all_children_visited(temp, us))
            {
                cout << temp->data << " ";
            }
            else
            {

                if (temp->left)
                {
                    s2.push(temp->left);
                    mark_visited(temp->left, us);
                }
                if (temp->right)
                {
                    s2.push(temp->right);
                    mark_visited(temp->right, us);
                }

                cout << temp->data << " ";
            }
        }

        while (!s2.empty())
        {
            node *temp = s2.top();
            // cout << "popped " << temp->data << "\n ";
            s2.pop();

            if (leaf_node(temp) || all_children_visited(temp, us))
            {
                cout << temp->data << " ";
            }
            else
            {

                if (temp->right)
                {
                    s1.push(temp->right);
                    mark_visited(temp->right, us);
                }

                if (temp->left)
                {
                    s1.push(temp->left);
                    mark_visited(temp->left, us);
                }
                cout << temp->data << " ";
            }
        }
    }
    cout << endl;
}
void tree_inorder_optimised(node *root)
{
    stack<node *> s;
    node *runner = root;
    while (!s.empty() || runner)
    {
        //
        // push every node while going left
        //
        while (runner)
        {
            s.push(runner);
            runner = runner->left;
        }
        //
        // runner is tired, top Up it.
        //
        runner = s.top();
        cout << runner->data << " ";
        s.pop();
        //
        // go right
        //
        runner = runner->right;
    }
    cout << endl;
}

void tree_preorder_optimised(node *root)
{
    stack<node *> s;
    node *runner = root;
    while (!s.empty() || runner)
    {
        //
        // push every node while going left
        //  
        while (runner)
        {
            cout << runner->data << " ";
            s.push(runner);
            runner = runner->left;
        }
        //
        // runner is tired, top Up it.
        //
        runner = s.top();
        s.pop();
        //
        // go right
        //
        runner = runner->right;
    }
    cout << endl;
}
int main()
{
    //
    // Non Perfect Tree
    //
    node *root = new node(1);
    add_node(root, {2, 4}, {'L', 'L'});
    add_node(root, {2, 13, 8}, {'L', 'R', 'R'});
    add_node(root, {3, 17}, {'R', 'R'});
    add_node(root, {3, 9}, {'R', 'L'});

    //
    // Perfect Tree
    //
    node *root1 = new node(1);
    add_node(root1, {2, 4}, {'L', 'L'});
    add_node(root1, {2, 13}, {'L', 'R'});
    add_node(root1, {3, 17}, {'R', 'R'});
    add_node(root1, {3, 8}, {'R', 'L'});

    cout << "\n---- printing the Non perfect tree ----\n";
    print_tree(root);
    cout << "\n---- printing the perfect tree ----\n";
    print_tree(root1);

    cout << "\nmaximum element of the tree =  " << tree_max(root) << endl;
    cout << "maximum height of the tree =  " << tree_height(root) << endl;
    cout << "number of nodes in the Tree =  " << tree_count_node(root) << endl;
    cout << "number of leaf nodes in the Tree =  " << tree_count_leaf(root) << endl;
    (tree_element_exist(root, 17) ? (cout << "Search: Value 17 exist\n") : (cout << "Search: Value 17 doesn't exist\n"));
    (tree_element_exist(root, 177) ? (cout << "Search: Value 177 exist\n") : (cout << "Search: Value 177 doesn't exist\n"));
    (tree_perfect(root) ? (cout << "Tree is Perfect\n") : (cout << "Tree is not Perfect\n"));
    (tree_perfect(root1) ? (cout << "Tree is Perfect\n") : (cout << "Tree is not Perfect\n"));

    cout << "\nInorder traversal of the tree iterative " << endl;
    tree_inorder_iter(root);

    cout << "\nInorder traversal (optimised )of the tree iterative " << endl;
    tree_inorder_optimised(root);

    cout << "\nSpiral traversal of the tree iterative " << endl;
    tree_spiral_traversal(root);

    cout << "\nPreorder traversal (optimised )of the tree iterative " << endl;
    tree_preorder_optimised(root);

    delete (root);
    delete (root1);
    return 0;
}