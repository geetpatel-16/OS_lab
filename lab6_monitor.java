class control{
	boolean flag = false;
	int value;
	synchronized void put(int value){
		if(flag)
		try{
			wait();
		}
		catch(InterruptedException x){
			System.out.println("InterruptedException caught");
		}
		this.value = value;
		flag = true;
		System.out.println("Put: " + value);
		notify();
	}
	synchronized int get(){
	if(!flag){
	try{
	wait();
	}
	catch(InterruptedException x){
		
	System.out.println("InterruptedException caught");
	}
	}

	System.out.println("Got: " + value);
	flag = false;
	notify();
	return value;
	}

	
}
class Consumer implements Runnable{
	control c;
	Consumer(control c){
	this.c = c;
	new Thread(this, "Consumer").start();
	}
	public void run(){
	while(true){
	c.get();
	}
	}
}
class Producer implements Runnable{
	int i;
	control c;
	Producer(control q){
	this.c = c;
	new Thread(this, "Producer").start();
	}
	
	public void run(){
	i = 0;
	while(true){
	c.put(i++);
	}
	}
}



class Monitor
{
	public static void main(String args[]){
	control c = new control();
	new Producer(c);
	new Consumer(c);
		
	}
}
