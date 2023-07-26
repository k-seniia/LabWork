import java.util.concurrent.CountDownLatch;

public class Race {
    private static final int NUM_CARS = 10;
    private CountDownLatch startLatch;
    private CountDownLatch readyLatch;
    private CountDownLatch goLatch;

    public Race() {
        startLatch = new CountDownLatch(NUM_CARS);
        readyLatch = new CountDownLatch(1);
        goLatch = new CountDownLatch(1);
    }

    public void startRace() throws InterruptedException {
        System.out.println("Cars are approaching the starting line.");

        Thread[] carThreads = new Thread[NUM_CARS];
        for (int i = 0; i < NUM_CARS; i++) {
            carThreads[i] = new Thread(new Car(i + 1));
            carThreads[i].start();
        }

        startLatch.await(); // Очікуємо, поки всі автомобілі під'їдуть до стартової прямої

        System.out.println("Get ready!");
        readyLatch.countDown(); // Віддаємо команду "Увага!"
        Thread.sleep(1000); // Затримка перед виконанням команди "Марш!"
        System.out.println("Go!");
        goLatch.countDown(); // Віддаємо команду "Марш!"

        for (Thread carThread : carThreads) {
            carThread.join(); // Очікуємо завершення всіх автомобілів
        }

        System.out.println("Race finished!");
    }

    private class Car implements Runnable {
        private int carNumber;

        public Car(int carNumber) {
            this.carNumber = carNumber;
        }

        @Override
        public void run() {
            System.out.println("Car " + carNumber + " is approaching the starting line.");
            startLatch.countDown(); // Зменшуємо лічильник під'їжджаючих автомобілів

            try {
                readyLatch.await(); // Очікуємо команди "Увага!"
                goLatch.await(); // Очікуємо команди "Марш!"
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Car " + carNumber + " has started the race.");
            // Логіка гонки для автомобіля
            System.out.println("Car " + carNumber + " has finished the race.");
        }
    }

    public static void main(String[] args) {
        try {
            Race race = new Race();
            race.startRace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}