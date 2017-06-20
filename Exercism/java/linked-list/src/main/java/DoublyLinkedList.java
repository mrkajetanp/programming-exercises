/**
 * Created by cajetan on 6/20/17.
 */

public class DoublyLinkedList<E> {
    private DLNode<E> head;
    private DLNode<E> tail;

    public DoublyLinkedList() {
        this.head = null;
        this.tail = null;
    }

    public void push(E item) {
        if (this.head == null) {
            this.head = new DLNode<>(item);
            this.tail = this.head;
        } else {
            this.tail.setNext(new DLNode<>(item));
            this.tail.getNext().setPrev(this.tail);
            this.tail = this.tail.getNext();
        }
    }

    public E pop() {
        E value = this.tail.getValue();

        if (this.head == this.tail) {
            this.head = this.tail = null;
        } else {
            this.tail.getPrev().setNext(null);
            this.tail = this.tail.getPrev();
        }

        return value;
    }

    public E shift() {
        E value = this.tail.getValue();

        return value;
    }

    public void unshift(E item) {

    }
}
