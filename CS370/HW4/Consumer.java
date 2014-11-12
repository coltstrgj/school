
public class Consumer implements Runnable  {
	private int ONEMILLIONDOLLARS=1000000, print_size=100000;
	
	private BoundedBuffer buffer;
	private double sum;
	public Consumer(BoundedBuffer buffer){
		this.buffer=buffer;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0; i<ONEMILLIONDOLLARS; i++){
			sum+=buffer.consume();
			if((i+1)%print_size==0)
				System.out.printf("Consumer: Consumed %d,000 items, Cumulative value of consumed items=%f\n", (i+1)/1000, sum);
		}
		System.out.println("Consumer: Finished consuming 1,000,000 items");
	}

}
