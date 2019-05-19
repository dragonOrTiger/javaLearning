public enum Day{
	MONDAY("星期一"),
	TUESDAY("星期二"),
	WEDNESDAY("星期三"),
	THURSDAY("星期四"),
	FRIDAY("星期五"),
	SATURDAY("星期六"),
	SUNDAY("星期天");

	private String desc;

	private Day(String desc){
		this.desc=desc;
	}

	public String getDesc(){
		return this.desc;
	}
}
