import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public final class Account {
    public int uid;
    public int balance;
    public Log log;
    public int initialBalance;

    public ReentrantLock balanceLock;
    public ReentrantLock logLock;


    public Account(int uid, int balance) {
        this.uid=uid;
        this.initialBalance = balance;
        this.balance = balance;
        this.balanceLock = new ReentrantLock();
        this.logLock = new ReentrantLock();
        this.log = new Log();
    }

    public boolean makeTransfer(Account other, int sum){
        if (sum>balance){
            return false;
        }

        if (this.uid<other.uid){
            this.balanceLock.lock();
            other.balanceLock.lock();
        }
        else {
            other.balanceLock.lock();
            this.balanceLock.lock();
        }

        balance-=sum;
        other.balance+=sum;
        long timestamp = System.currentTimeMillis();
        logTransfer(OperationType.SEND,this.uid, other.uid,sum, timestamp);
        other.logTransfer(OperationType.RECEIVE,other.uid, this.uid, sum, timestamp);

        this.balanceLock.unlock();
        other.balanceLock.unlock();

        return true;
    }


    public void logTransfer(OperationType type, int src, int dest, int sum, long timestamp){
        log.log(type,sum, src, dest, timestamp);
    }

    public boolean check() {
        int initBalance = this.initialBalance;
        for (Operation operation: this.log.operations){
            if (operation.type==OperationType.SEND)
                initBalance-=operation.amount;
            else
                initBalance+=operation.amount;
        }
        return initBalance==this.balance;
    }


}