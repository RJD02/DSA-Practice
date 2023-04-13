class buy_car{
    public static void main (String[] args) {
        Car c=new Honda();
        c.print();
    }
}
class Vehicle{
    String colour;
    private int number;
    void print()
    {
        System.out.println("vehicle");
    }
}

class Car extends Vehicle{
    void print()
    {
        System.out.println("car");
    }
}
class Honda extends Car{
    void print()
    {
        System.out.println("Honda");
    }
}


