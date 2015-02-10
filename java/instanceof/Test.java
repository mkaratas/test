import java.util.ArrayList;


class Contacts {
	private ArrayList<String> mLinkName = new ArrayList<String>();
	private int mNum;

	Contacts(int n) {
		mNum = n;
		System.out.println("Constacts construction");
	}

	int getNum() {
		return mNum;
	}
}

public class Test {



	public static final void main(String [] args) {
		System.out.println("hello world");
		Contacts contacts = new Contacts(10);

		System.out.println("Num = " + contacts.getNum());
	
		String s = "I am a Object";
		if (s instanceof Object) {
			System.out.println("Yes");
		} else {
			System.out.println("No");

		}
	}
}
