package cn.cjz.callback;

interface CallBack {
	//void printName();
	//void printAge(); 
	void execute();
}

class Class2 implements CallBack {
	public void execute() {
		System.out.println("in Class2 execute.");
	}
}

public class Test {
	public void testTime(CallBack callBack) {
		long begin = System.currentTimeMillis();
		try {
			Thread.sleep(1000);
		} catch (InterruptedException i) {
			
		}
		callBack.execute();
		long end = System.currentTimeMillis();
		System.out.println("[use time]:" + (end - begin));
	}

	//static CallBack cb;

	
	public static void main(String [] args) {
		CallBack cb = new Class2();
		cb.execute();
	}
}
