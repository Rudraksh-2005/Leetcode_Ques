class Solution {
public:

    Node* flatten(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* curr = head;

        while (curr != nullptr) {

            // If there is no child, continue normally
            if (curr->child == nullptr) {
                curr = curr->next;
                continue;
            }

            Node* nextNode = curr->next;

            // Flatten child list recursively
            Node* childHead = flatten(curr->child);

            // Connect current node with child
            curr->next = childHead;
            childHead->prev = curr;

            // Remove child pointer
            curr->child = nullptr;

            // Find tail of flattened child list
            Node* tail = childHead;

            while (tail->next != nullptr) {
                tail = tail->next;
            }

            // Connect tail with original next node
            if (nextNode != nullptr) {
                tail->next = nextNode;
                nextNode->prev = tail;
            }

            curr = nextNode;
        }

        return head;
    }
};