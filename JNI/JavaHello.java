public class JavaHello {
	public static native String hello();
	static {
	// load library: libtest.so
		try {
			System.loadLibrary("test");
		} catch (UnsatisfiedLinkError ule) {
			System.err.println("WARNING: Could not load library!");
		}
	}
	public static void main(String[] args) {
		String s = new JavaHello().hello();
		System.out.println(s);
	}
}
