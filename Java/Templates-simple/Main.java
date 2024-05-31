
public class Main {
    public static void main(String[] args) {
        Variables variables = new Variables();
        variables.convertText("Lorem ipsum {contract number:int:10} dolor sit amet,\n" +
                "consectetur adipiscing elit, sed do eiusmod {first name:string}\n" +
                "{family name:string:upper} tempor incididunt ut labore et dolore\n" +
                "magna aliqua. Ut enim ad minim veniam, quis {years:int} nostrud\n" +
                "exercitation ullamco {price:float} laboris nisi ut aliquip ex ea\n" +
                "commodo consequat. Duis aute irure dolor in reprehenderit in\n" +
                "voluptate velit esse cillum dolore eu fugiat nulla pariatur.\n" +
                "Excepteur sint {small text:string:lower} occaecat cupidatat non\n" +
                "proident, {rate:float:4} sunt in culpa qui officia deserunt mollit\n" +
                "anim id est laborum.");

    }
}