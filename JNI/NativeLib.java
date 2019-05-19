public class NativeLib{
	static{
		try {
			System.loadLibrary("NativeLib");
		} catch (UnsatisfiedLinkError ule) {
			System.out.println("WARNING: Could not load library!");
		}
	}

	public static native String getNativeString();
	public static void main(String args[]){
		NativeLib test =  new NativeLib();
		String result = test.getNativeString();
		System.out.println(result);
	}
}
