/// too musch to nuderstand


class Node {
    int data;
    Node next;
    Node prev;

    Node(int val){
        data = val;
        this.next=null;
        this.prev=null;

    }
}

class bitinoc_sort{
    static void prnitList(Node head){
        while (head != null){
            System.out.print(head.data+" ");
            head=head.next;
        }
        System.out.println();

    }

    static Node sorting(Node head){
        if (head == null || head .next == null )
            return head;

        Node last = head;
        while (last.next != null){
            last = last.next;
        }
        Node front = head;
        Node result=null;
        Node tail =null;

        while(front != null && last !=null && front != last && last.next !=front){
            Node newNode;
            if(front.data <last.data){
                newNode =new Node(front.data);
                front =front.next;
            }
            else{
                newNode=new Node(last.data);
                last =last.prev;

            }

            if(result == null){
                result =newNode;
                tail=result;

            }
            else{
                tail.next=newNode;
                newNode.prev=tail;
                tail=tail.next;

            }
        }

        while(front != null && front != last.next ){
            Node newNode= new Node(last.data);
           front=front.next;
           tail.next=newNode;
           newNode.prev=tail;
           tail=tail.next;
           
        }
        while(last !=null && last.next != front){
            Node newNode = new Node(last.data);
            last = last.prev;
            tail.next = newNode;
            newNode.prev=tail;
            tail=tail.next;

        }
        return result;
    }
    public static void main(String[] args){
        Node head= new Node(2);
        head.next =new Node(12);
        head.next.prev=head;
        head.next.next=new Node(11);
        head.next.next.prev=head.next;
        head.next.next.next=new Node(1);
        head.next.next.next.prev=head.next.next;
         prnitList(head);
        Node result_head= sorting(head);
        prnitList(result_head);
    }
}