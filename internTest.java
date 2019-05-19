public class internTest{
	public static void main(String[] args){
		/*
		String str1 = "Hello";
		String str2 = new String("Hello");
		String str3 = str2.intern();
		System.out.println(str1 == str2);
		System.out.println(str1 == str3);
		*/
		/*
		String str4 = "HelloWorld";
		String str5 = "Hello" + "World";
		final String baseFinalStr = "Hello";
		String str6 = baseFinalStr + "World";
		String baseStr = "Hello";
		String str7 = baseStr + "World";
		String str8 = new String("HelloWorld").intern();
		System.out.println(str4 == str5);
		System.out.println(str4 == str6);
		System.out.println(str4 == str7);
		System.out.println(str4 == str8);
		*/
		String str9 = new String("Hello") + new String("World");
		str9.intern();
		//String str10 = "HelloWorld";
		//System.out.println(str9 == str10);
		/*
		String str11 = "HelloWorld";
		String str12 = new String("Hello") + new String("World");
		str12.intern();
		System.out.println(str11 == str12);
		*/
	}
}
