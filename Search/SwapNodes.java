import java.util.*;

class Node {
    public int data;
    public int depth;
    public Node left;
    public Node right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
        this.depth = 1;
    }
}

public class Solution {
    static ArrayList<Integer> inOrderTraverseResult;

    static void inOrderTraverse(Node n) {
        if (n != null){
            inOrderTraverse(n.left);
            inOrderTraverseResult.add(n.data + 1);
            inOrderTraverse(n.right);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(); // Number of Nodes N
        in.nextLine();

        // Create the binary tree
        Node[] nodes = new Node[N];
        for (int i = 0; i < N; i++) {
            nodes[i] = new Node(i);
        }

        // This one will be handy for the swapping below
        Map<Integer, ArrayList<Integer>> depthMap = new HashMap<Integer, ArrayList<Integer>>();

        String nextNode;
        String[] nextNodeSplit;
        int left;
        int right;

        for (int i = 0; i < N; i++) {
            nextNode = in.nextLine();
            nextNodeSplit = nextNode.split(" ");
            left = Integer.parseInt(nextNodeSplit[0]);
            right = Integer.parseInt(nextNodeSplit[1]);

            if (left != -1) {
                nodes[i].left = nodes[left - 1];
                nodes[i].left.depth = nodes[i].depth + 1;
            }

            if (right != -1) {
                nodes[i].right = nodes[right - 1];
                nodes[i].right.depth = nodes[i].depth + 1;
            }

            if (!depthMap.containsKey(nodes[i].depth)) {
                depthMap.put(nodes[i].depth, new ArrayList<Integer>());
            }
            depthMap.get(nodes[i].depth).add(i);
        }


        // Now we will read the `swaps they want us to do` data
        int T = in.nextInt(); // Number of Test swaps
        in.nextLine();

        int K;
        for (int i = 0; i < T; i++) {
            K = in.nextInt();

            // Get the multiples by 2 on K to get the depth h
            for (int h = K; h <= N; h += K) {
                if (!depthMap.containsKey(h)) break;
                // Iterate over the indexes on that depth
                int nodeIdx, nodeLeftIdx, nodeRightIdx;
                for (int n = 0; n < depthMap.get(h).size(); n++) {
                    nodeIdx = depthMap.get(h).get(n);

                    if (nodes[nodeIdx].left != null) {
                        nodeLeftIdx = nodes[nodeIdx].left.data;
                    } else {
                        nodeLeftIdx = 0;
                    }

                    if (nodes[nodeIdx].right != null) {
                        nodeRightIdx = nodes[nodeIdx].right.data;
                    } else {
                        nodeRightIdx = 0;
                    }

                    nodes[nodeIdx].left = nodeRightIdx != 0 ? nodes[nodeRightIdx] : null;
                    nodes[nodeIdx].right = nodeLeftIdx != 0 ? nodes[nodeLeftIdx] : null;
                }
            }

            inOrderTraverseResult = new ArrayList<Integer>();
            inOrderTraverse(nodes[0]);
            String result = "";
            for (int tr = 0; tr < inOrderTraverseResult.size(); tr++) {
                if (tr != 0) {
                    result += " ";
                }
                result += inOrderTraverseResult.get(tr);
            }
            System.out.println(result);
        }
    }
}
