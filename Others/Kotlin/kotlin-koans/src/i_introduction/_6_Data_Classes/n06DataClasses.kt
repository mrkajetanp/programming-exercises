package i_introduction._6_Data_Classes

import util.TODO
import util.doc6

fun todoTask6(): Nothing = TODO(
    """
        Convert 'JavaCode6.Person' class to Kotlin.
        Then add a modifier `data` to the resulting class.
        This annotation means the compiler will generate a bunch of useful methods in this class:
        `equals`/`hashCode`, `toString` and some others.
        The `task6` function should return a list of persons.
    """,
    documentation = doc6(),
    references = { JavaCode6.Person("Alice", 29) }
)

data class Person(val name: String, val age: Int)

fun task6(): List<Person> {

    return listOf(Person("Alice", 29), Person("Bob", 31))
}


//public class JavaCode6 extends JavaCode {
//
//    public static class Person {
//        private final String name;
//        private final int age;
//
//        public Person(String name, int age) {
//            this.name = name;
//            this.age = age;
//        }
//
//        public String getName() {
//            return name;
//        }
//
//        public int getAge() {
//            return age;
//        }
//    }
//}
