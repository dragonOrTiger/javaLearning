import java.util.ArrayList;

public class TestJNIObjectArray{
	static {
		System.loadLibrary("myjni");//myjni.dll(Windows) or libmyjni.so(Unixes)
	}
	//Native method that receives an Integer[] and 
	//returns a Double[2] with [0] as num and [1] as average
	private native Double[] sumAndAverage(Integer[] numbers);
	
	public static void main(String args[]){
		Integer[] numbers = {11, 22, 33};//auto-box
		Double[] results = new TestJNIObjectArray().sumAndAverage(numbers);
		System.out.println("In Java, the sum is " + results[0]);
		System.out.println("In Java, the average is " + results[1]);
	}
}
