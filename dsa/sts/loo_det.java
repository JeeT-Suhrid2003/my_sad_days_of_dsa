import java.util.HashSet;
import java.util.Set;

class Node{
    int data;
    Node next;

    Node(int x){
        this.data=x;
        this.next=null;
    }

}

class loo_det{
    static boolean detec(Node head){
        Set<Node> st =new HashSet<>();

        while(head != null){
            if(st.contains(head))
                return true;
            
            st.add(head);
            head = head.next;

        }
        return false;
    }

    public static void main(String[] args){

        Node head =new Node(10);
        head.next = new Node(20);
        head.next.next=new Node(30);
        head.next.next.next= new Node(40);
        head.next.next.next.next= new Node(80);
        head.next.next.next=head;
        
        if (detec(head)){
            System.out.println("true");
        } 
        else{
            System.out.print("flase");
        }
    }


}