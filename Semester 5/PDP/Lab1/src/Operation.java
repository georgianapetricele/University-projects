public class Operation {
    private final Account source;
    private final Account destination;

    public Operation(Account source, Account destination) {
        this.source = source;
        this.destination = destination;
    }

    public void transfer(final int sum) {

        this.source.balanceLock.lock();
        try {
            this.destination.balanceLock.lock();
            try {
                if (source.getBalance() - sum < 0) {
                    return;
                }

                source.withdraw(sum);
                destination.deposit(sum);

                OperationRecord record = new OperationRecord(source, destination, sum);
                source.addLog(record);
                destination.addLog(record);

            } finally {
                this.destination.balanceLock.unlock();
            }
        } finally {
            this.source.balanceLock.unlock();
        }
    }
}
