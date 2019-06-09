/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  let carried = 0;
  const head = new ListNode();
  const noop = {
    val: 0,
    next: null
  };

  let currentL1 = l1;
  let currentL2 = l2;
  let currentNode = head;

  let newNode, previousNode;

  while(currentL1 || currentL2) {
    newNode = new ListNode(0);

    currentNode.val = ((currentL1 || noop).val + (currentL2 || noop).val + carried) % 10;
    currentNode.next = newNode;
    previousNode = currentNode;
    currentNode = newNode;

    if ((currentL1 || noop).val + (currentL2 || noop).val + carried >= 10) {
      carried = 1;
    } else {
      carried = 0;
    }

    currentL1 = (currentL1 || noop).next;
    currentL2 = (currentL2 || noop).next;
  }

  if (carried) {
    // 还有位没进呢
    previousNode.next = new ListNode(carried)
  } else {
    previousNode.next = null;
  }

  return head;
};
