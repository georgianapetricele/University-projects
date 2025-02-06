import Message.BaseMessage;
import Message.CloseMessage;
import Message.SubscribeMessage;
import Message.UpdateMessage;
import mpi.MPI;

public class Subscriber implements Runnable{
    private final DSMSystem dsm;

    public Subscriber(DSMSystem dsm) {
        this.dsm = dsm;
    }

    @Override
    public void run() {
        while (true) {
            System.out.println("<" + MPI.COMM_WORLD.Rank() + "> is waiting...");
            Object[] messagesObject = new Object[1];

            MPI.COMM_WORLD.Recv(messagesObject, 0, 1, MPI.OBJECT, MPI.ANY_SOURCE, MPI.ANY_TAG);
            BaseMessage message = (BaseMessage) messagesObject[0];
            if (message instanceof CloseMessage) {
                System.out.println("Process <" +MPI.COMM_WORLD.Rank() + "> stopped!");
                break;
            } else if (message instanceof SubscribeMessage subscribeMessage) {
                System.out.println("Subscriber message in process <" + MPI.COMM_WORLD.Rank() + ">: " + subscribeMessage.rank + " subscribes to " + subscribeMessage.variable);
                // now notify all processes of the new subscriber
                this.dsm.syncSubscription(subscribeMessage.variable, subscribeMessage.rank);
            }  else if (message instanceof UpdateMessage updateMessage) {
                // got the update message to now set the variable to the map
                System.out.println("Update message in process <" + MPI.COMM_WORLD.Rank() + ">: " + updateMessage.variable + " -> " + updateMessage.value);
                this.dsm.setVariable(updateMessage.variable, updateMessage.value);
            }
        }
        System.out.println("Finalizing <" + MPI.COMM_WORLD.Rank() + "> - " + this.dsm);
    }
}