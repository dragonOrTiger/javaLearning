public class StringDemo{
	public static void main(String args[]){
		String str1 = new StringBuilder("计算机").append("系统").toString();
        System.out.println(str1.intern() == str1);
		String str2 = new StringBuilder("In").append("tern").toString();
        System.out.println(str2.intern() == str2);
        String str4 = new StringBuilder("ja").append("va").toString();
        System.out.println(str4.intern() == str4);
        String str3 = new StringBuilder("计算机").append("系统").toString();
        System.out.println(str3.intern() == str3);
        System.out.println(str1.intern() == str3.intern());
	}
}
