interface People {
	void peopleList();
}

class Student implements People {
	public void peopleList() {
		System.out.println("I am a student.");
	}
}

class Teacher implements People {
	public void peopleList() {
		System.out.println("I am a teacher.");
	}
}

public class Example {
	public static void main(String args[]) {
		People a;
		People b;
	
		a = new Student();
		a.peopleList();
		b = new Teacher();
		b.peopleList();
	}
}
