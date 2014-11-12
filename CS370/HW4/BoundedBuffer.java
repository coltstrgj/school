import java.util.LinkedList;
public class BoundedBuffer {
	private LinkedList<Double> buffer;
	/*I wanted to implement my own linked list so that the get() would be O(1) and
	 *you would only have to check if consumer_pos.next == producer and visav
	 *because I would only increment each after completely finishing it's job, the other
	 *would never override the data it was reading. It would have been much more efficient
	 *but I never got it to work properly 
	 *
	 *instead I use the ints below to mark position
	 */
	private int consumer_pos=0, producer_pos=0, size;//last position read or written.(that means that the buffer will start filling at pos 1)
	
	
	public BoundedBuffer(int size){
		buffer=new LinkedList<Double>();
		this.size=size;
		for(int i=0; i<size; i++){
			buffer.add(null);
		}
	}
/*************************************************************************************************/
	public synchronized void produce(double product){
		/*whole method cannot run at the same time as consume because
		 * we may end up blocking ourselves and there is a chance
		 * that they could do the same if we get context switched
		 */
		int producer_pos_next=(producer_pos+1)%size;
		if(producer_pos_next==consumer_pos){//the next one is the last on that consumer consumed
			try {
				wait();
			} catch (InterruptedException e) {}//we want this to happen
		}
		//we are good to go	
		buffer.set(producer_pos_next, product);
		producer_pos=producer_pos_next;//keep it in the circular buffer
		notify();//should release consumer if it was blocking
		return;
	}
/*************************************************************************************************/
	public synchronized double consume(){
		double product;
		int consumer_pos_next=(consumer_pos+1)%size;
		if(consumer_pos_next==(producer_pos+1)%size){
			try {
				wait();
			} catch (InterruptedException e){}//we want this to happen
			//consumer.wait(producer);//wait until the producer has produced at least one more
		}
		product=buffer.get(consumer_pos_next);
		consumer_pos=consumer_pos_next;
		notify();
		return product;
	}

}