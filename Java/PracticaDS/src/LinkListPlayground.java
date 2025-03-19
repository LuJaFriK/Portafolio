public class LinkListPlayground {
    public static void main(String[] args) {
        Node head = new Node(1);
        Node node1 = new Node(2);
        Node node2 = new Node(3);
        Node node3 = new Node(4);

        head.next = node1;
        node1.next = node2;
        node2.next = node3;
        head= deleteNode(head, 3);
        head = addNode(head, 5);
        head = preNode(head,0);
        head = setNode(head, 1, 6);
        Node tempNode = head;
        while(tempNode != null){
            System.out.println(tempNode.value);
            tempNode = tempNode.next;
        }
    }
    public static Node deleteNode(Node head, int value) {
        Node tempNode = head;
        if(head.value == value){
            return head.next;}else {
            while (tempNode.next != null) {
                if (tempNode.next.value == value) {
                    tempNode.next = tempNode.next.next;
                    break;
                } else {
                    tempNode = tempNode.next;

                }
            }
        }

        return head;
    }
    public static Node addNode(Node head, int value){
        Node tempNode = head;
        while (tempNode.next != null) {
            tempNode = tempNode.next;
        }
        tempNode.next = new Node (value);
        return head;
    }
    public static Node preNode(Node head, int value){
        Node newhead = new Node(value);
        newhead.next = head;
        return newhead;
    }
    public static Node setNode(Node head, int pos, int value) {
        Node tempNode = head;
        for(int i = 0; i < pos - 1 && tempNode != null; i++) {
            tempNode = tempNode.next;
        }

        if(tempNode != null && tempNode.next != null) {
            tempNode.next.value = value;
        }

        return head;
    }
}
