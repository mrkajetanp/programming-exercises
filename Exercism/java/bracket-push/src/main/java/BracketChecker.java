import java.util.Stack;

final class BracketChecker {
    private boolean areMatched;

    public BracketChecker(String text) {
        this.areMatched = checkBrackets(text);
    }

    private boolean checkBrackets(String text) {
        Stack<Character> bracketStack = new Stack<>();

        for (char c : text.toCharArray()) {
            switch (c) {
                case '[':
                    bracketStack.push(c);
                    break;

                case ']':
                    if (bracketStack.isEmpty() || bracketStack.pop() != '[')
                        return false;
                    break;

                case '{':
                    bracketStack.push(c);
                    break;

                case '}':
                    if (bracketStack.isEmpty() || bracketStack.pop() != '{')
                        return false;
                    break;

                case '(':
                    bracketStack.push(c);
                    break;

                case ')':
                    if (bracketStack.isEmpty() || bracketStack.pop() != '(')
                        return false;
                    break;
            }
        }

        return bracketStack.isEmpty();
    }

    public boolean areBracketsMatchedAndNestedCorrectly() {
        return this.areMatched;
    }
}