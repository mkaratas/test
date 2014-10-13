package com.designpattern.template;

interface TestTemplateCallBack {
	Object doSomething();

}

class Template2 {
	public void execute(TestTemplateCallBack callBack) {
		try {
			System.out.println("task begin.");
			System.out.println("task performing.");
			callBack.doSomething();
			System.out.println("task finished.");
		} catch (Exception e) {
			System.out.println("error, go back.");
			e.printStackTrace();
		}
	}
}

public class TemplateTest2 {
	public void insert(final String msg) {
		Template2 t = new Template2();
		t.execute(new TestTemplateCallBack() {
			public Object doSomething() {
				System.out.println("insert:" + msg);
				return null;
			}
		}); 
	}

	public static void main(String [] args) {
		TemplateTest2 t = new TemplateTest2();
		t.insert("Hello");
	}
}
