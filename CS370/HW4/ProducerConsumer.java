import java.util.Random;
public class ProducerConsumer {
	
	
	public static void main(String[] args) {
		// Create buffer for them to share and cherish
		BoundedBuffer buffer=new BoundedBuffer(4);
		//create the producer thread
		Producer producer = new Producer(buffer);
		Thread producer_thread=new Thread(producer);
    	producer_thread.start();
    	//and the consumer thread
    	Consumer consumer = new Consumer(buffer);
    	Thread consumer_thread=new Thread(consumer);
	    consumer_thread.start();
	    try {
			consumer_thread.join();
			producer_thread.join();
		} catch (InterruptedException e) {} 
	    System.out.println("Exiting!");
	    
	}
}
