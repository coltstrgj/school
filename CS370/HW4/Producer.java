import java.util.Random;
public class Producer implements Runnable {
	private int ONEMILLIONDOLLARS=1000000, print_size=100000;
	//the  max number that you want to produce/consume, and how often you want to print
	//print must be greater than 1,000 if you want the printline to look proper
	
	private BoundedBuffer buffer;
	private double sum;
	
	public Producer(BoundedBuffer buffer){
		sum=0;
		this.buffer=buffer;
	}
	@Override
	public void run() {
		//the following is "stolen" from instructions
		Random random = new Random();
		for(int i=0; i<ONEMILLIONDOLLARS; i++){
			Double bufferElement = random.nextDouble() * 100.0;
			sum+=bufferElement;
			buffer.produce(bufferElement);
			if((i+1)%print_size==0)
				System.out.printf("Producer: Generated %d,000 items, Cumulative value of generated items=%f\n", (i+1)/1000, sum);
		}
		System.out.println("Producer: Finished generating 1,000,000 items");
	}

}
