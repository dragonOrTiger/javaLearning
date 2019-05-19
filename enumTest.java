public class enumTest{
	public static void main(String args[]){
	    System.out.println(Day.MONDAY.getDesc());
	    System.out.println(Day.TUESDAY.getDesc());
	    System.out.println(Day.WEDNESDAY.getDesc());
	    System.out.println(Day.THURSDAY.getDesc());
	    System.out.println(Day.FRIDAY.getDesc());
	    System.out.println(Day.SATURDAY.getDesc());
	    System.out.println(Day.SUNDAY.getDesc());
	    for(int i=0;i<Day.values().length;i++){
	         System.out.println(Day.values()[i].getDesc());
	    }
	    System.out.println(Day.valueOf("MONDAY"));
	}
}
