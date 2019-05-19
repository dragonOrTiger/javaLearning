public class TestJNIStaticVariable{
	static{
		System.loadLibrary("myjni");//myjni.dll(WIndows) or libmyjni.so(Unixes)
	}

	//Static variables
	private static double number = 55.66;

	//Declare a native method that modifies the static variables
	private native void modifyStaticVariable();

	//Test Driver
	public static void main(String args[]){
		TestJNIStaticVariable test = new TestJNIStaticVariable();
		test.modifyStaticVariable();
		System.out.println("In Java, the double is " + test.number);
	}
}
