import java.util.ArrayDeque;
import java.util.Deque;

public class BraceChecker {

    public boolean isValid(String braces) {
        Deque<Character> bracketStack = new ArrayDeque<>();

        for (char c : braces.toCharArray()) {
            switch (c) {
                case '(': case '{': case '[':
                    bracketStack.push(c);
                    break;

                case ')':
                    if (bracketStack.isEmpty()  || bracketStack.pop() != '(')
                        return false;
                    break;

                case '}':
                    if (bracketStack.isEmpty()  || bracketStack.pop() != '{')
                        return false;
                     break;

                case ']':
                    if (bracketStack.isEmpty()  || bracketStack.pop() != '[')
                        return false;
                     break;
            }
        }

        return bracketStack.isEmpty();
    }

}