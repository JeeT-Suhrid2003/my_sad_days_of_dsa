class Node{
    int data;
    Node next;

    Node(int data){
        this.data=data;
        this.next=null;
    }
}

public class segregate{

    public static Node sepEO(Node head){

        Node ress=null;
        Node rese=null;

        Node curr =head;
        Node prev = null;

        while (curr !=null){
            if(curr.data %2 == 0){
                if(prev != null){
                    prev.next=curr.next;
                }
                else{
                    head=curr.next;
                }


                if(ress== null){
                    ress= curr;
                    rese=ress;
                }
                else{
                    rese.next =curr;
                    rese=rese.next;
                }

                curr=curr.next;

            }else{
                prev=curr;
                curr=curr.next;
            }
        }
        
        if (ress==null){
            return head;

        }

        rese.next=head;

        return ress;
    }
    public static void prnitList(Node node){
        while(node != null){
            System.out.print(node.data +" ");
            node =node.next;
        }
        System.out.println();
        
    }
    public static void main(String[] args){
        Node head= new Node(0);
        head.next=new Node(1);
        head.next.next=new Node(5);
        head.next.next.next=new Node(7);
        head.next.next.next.next=new Node(10);
        head.next.next.next.next.next=new Node(11);

        System.out.println("original");
        prnitList(head);
        prnitList(sepEO(head));
    }

}