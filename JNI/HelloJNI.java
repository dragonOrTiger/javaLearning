/*
 *通过System.loadLibrary("hello")方法加载native模块"hello"(该模块包含了sayHello()方法)。
 *声明native方法: private native void sayHello();
 *在main方法中调用
*/
public class HelloJNI{
	static {
		/*执行命令java HelloJNI即可*/
		//System.load("/home/shiyongjie/java/JNI/libhello.so");
		/*执行命令java -Djava.library.path=. HelloJNI, 需要指定动态链接库的路径*/
		System.loadLibrary("hello");//Load native library at runtime
									//hello.dll(Windows) or libhello.so(Unixes)
	}
	//Declare a native method sayHello() that receives nothing and returns void
	private native void sayHello();
	//Test Driver
	public static void main(String[] args){
		new HelloJNI().sayHello();
	}
}
