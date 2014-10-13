using System;

namespace DesignPatterns.Strategy.Ducks
{
    public abstract class Duck
    {
        protected IFlyBehavior flyBehavior;
        protected IQuackBehavior quackBehavior;

        public string Swim()
        {
            return "���е�Ѽ�Ӷ�������Ӿ��";
        }

        public object PerformFly()
        {
            return flyBehavior.Fly();
        }

        public object PerformQuack()
        {
            return quackBehavior.Quack();
        }


        public void SetQuackBehavior(IQuackBehavior qck)
        {
            this.quackBehavior = qck;
        }

        public void SetFlyBehavoir(IFlyBehavior fly)
        {
            this.flyBehavior = fly;
        }

        public abstract object Display();     
    }
}
