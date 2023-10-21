/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isUnivalTree = function(root) {
    if(!root)return true;
    const uni = root.val;
    let queue = [root];
    let curNode;
    while(queue.length >0){
        curNode = queue.shift();
        if(curNode.val!== uni)return false;
        curNode.left && queue.push(curNode.left);
        curNode.right && queue.push(curNode.right);
    }
    return true;
};