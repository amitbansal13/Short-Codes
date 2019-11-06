class Food{
	public String name;
	public int caloriesPerServing;
	public int servingsPerContainer;
	public Food(String name,int caloriesPerServing,int servingsPerContainer){
		this.name=name;
		this.caloriesPerServing=caloriesPerServing;
		this.servingsPerContainer=servingsPerContainer;
	}
	public String toString(){
		return "Item Name - "name+"\nCalories per Serving - "+caloriesPerServing+"\nServings per Container - "+servingsPerContainer;
	}
}

public class Queue{
	private Food[] queue;
	private int front,back,size;
	public Queue(){
		size=20;
		queue=new Food[size];//initialize array with size of size Food references
		front=-1;
		back=-1;
	}
	public void enqueue(Food f){
		if((back+1)%size==front){//if next to rear is the front then queue is full
			System.out.println("Queue is full");
		}
		else{
			if(front==-1){//if first element to be inserted
				front=0;
			}
			back=(back+1)%size;
			queue[back]=f;
		}
	}
	public void dequeue(){
		if(front==-1 && back==-1)//if queue is empty the both are -1
		{
			System.out.println("Queue is empty");
			return;
		}
		if(front==back){//if there is only one element in queue
			front=back=-1;
		}
		else{//else move the front to next
			front=(front+1)%size;
		}
	}
	public Food peek(){
		if(front==-1 && back==-1)//if queue is empty
		{
			System.out.println("Queue is empty");
			return null;
		}
		return queue[front];//return first element
	}
	public double averageCalories(){
		if(front==-1 && back==-1)//if queue is empty then return 0
			return 0.0;
		double sum=0.0;
		int count=0;
		if(front<=back){
			for(int i=front;i<=back;i++){
				sum+=queue[i].caloriesPerServing;
				count++;
			}
			return sum/count;
		}
		else{
			int i=front;
			while(i<size){
				sum+=queue[i].caloriesPerServing;
				count++;
				i++;
			}
			i=0;
			while(i<=back){
				sum+=queue[i].caloriesPerServing;
				count++;
				i++;
			}
			return	sum/count;
		}
	}

	public int highestCalories(){
		//similar approach to average calories per serving
		if(front==-1 && back==-1)
			return 0;
		int max=0,cals;
		if(front<=back){
			for(int i=front;i<=back;i++){
				cals=queue[i].caloriesPerServing*queue[i].servingsPerContainer;
				if(cals>max){
					max=cals;
				}
			}
			return max;
		}
		int i=front;
		while(i<size){
			cals=queue[i].caloriesPerServing*queue[i].servingsPerContainer;
			if(cals>max){
				max=cals;
			}
			i++;
		}
		i=0;
		while(i<=back){
			cals=queue[i].caloriesPerServing*queue[i].servingsPerContainer;
			if(cals>max){
				max=cals;
			}
			i++;
		}
		return	max;
	}
	public static void main(String[] args){
		//Testing
		Queue q=new Queue();
		Food f1=new Food("a",10,size);
		Food f2=new Food("b",5,10);
		Food f3=new Food("c",size,5);
		Food f4=new Food("d",30,size);
		q.enqueue(f1);
		System.out.println(q.peek());
		System.out.println(q.averageCalories());
		q.enqueue(f3);
		q.enqueue(f2);
		System.out.println(q.highestCalories());
		q.enqueue(f4);
		System.out.println(q.highestCalories());
		System.out.println(q.averageCalories());
		q.dequeue();
		System.out.println(q.peek());
		System.out.println(q.highestCalories());
		System.out.println(q.averageCalories());
		
	}
}