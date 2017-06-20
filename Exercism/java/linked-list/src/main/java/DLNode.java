/**
 * Created by cajetan on 6/20/17.
 */
public class DLNode<E> {
    private E value;
    private DLNode<E> next;
    private DLNode<E> prev;

    public DLNode(E value) {
        this.value = value;
    }

    public E getValue() {
        return value;
    }

    public DLNode<E> getNext() {
        return next;
    }

    public void setNext(DLNode<E> next) {
        this.next = next;
    }

    public DLNode<E> getPrev() {
        return prev;
    }

    public void setPrev(DLNode<E> prev) {
        this.prev = prev;
    }
}
