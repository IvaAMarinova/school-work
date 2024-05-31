import java.util.Scanner;
import java.text.DecimalFormat;

public class Variables {
    public void convertText(String text) {
        char[] charTextArray = text.toCharArray();
        StringBuilder finalTextBuilder = new StringBuilder();

        int length = charTextArray.length;
        for (int i = 0; i < length; i++) {
            if (charTextArray[i] == '{') {
                StringBuilder variableType = new StringBuilder();
                StringBuilder variableIdentifier = new StringBuilder();
                i++;
                while (i < length && charTextArray[i] != ':') {
                    variableIdentifier.append(charTextArray[i]);
                    i++;
                }
                i++;
                while (i < length && charTextArray[i] != ':' && charTextArray[i] != '}') {
                    variableType.append(charTextArray[i]);
                    i++;
                }
                StringBuilder variableSpecifier = new StringBuilder();
                if(charTextArray[i] == ':') {
                    i++;
                    while(i < length && charTextArray[i] != '}') {
                        variableSpecifier.append(charTextArray[i]);
                        i++;
                    }
                }

                System.out.print("Please provide a " + variableType + " for " + variableIdentifier + ":");
                Scanner scanner = new Scanner(System.in);
                String input = scanner.next();

                String typeLowerCase = variableType.toString().toLowerCase();

                if(typeLowerCase.equals("string"))
                {
                    if(variableSpecifier.toString().equals("lower"))
                    {
                        if(!containsLetters(input) || containsUpperLetters(input))
                        {
                            throw new IllegalArgumentException("Input must be a string and no upper case letters");
                        }
                    } else if(variableSpecifier.toString().equals("upper"))
                    {
                        if(!containsLetters(input) || containsLowerLetters(input))
                        {
                            throw new IllegalArgumentException("Input must be a string and no lower case letters");
                        }
                    } else {
                        if(!containsLetters(input))
                        {
                            throw new IllegalArgumentException("Input must be a string");
                        }
                    }
                    finalTextBuilder.append(input);
                } else if(typeLowerCase.equals("int"))
                {
                    if (!variableSpecifier.toString().isEmpty()) {
                        int digits_count = Integer.parseInt(variableSpecifier.toString());
                        int input_count = input.length();

                        if (digits_count > input_count && !containsOnlyDigits(input)) {
                            throw new IllegalArgumentException("Invalid digits input");
                        }

                        for (int j = 0; j < digits_count - input_count; j++) {
                            finalTextBuilder.append("0");
                        }
                    } else if(!containsOnlyDigits(input))
                        {
                            throw new IllegalArgumentException("Input must be a number");
                        }
                        finalTextBuilder.append(input);
                } else if(typeLowerCase.equals("float"))
                {
                    if(input == null || !isValidFloat(input))
                    {
                        throw new IllegalArgumentException("Input must be a float");
                    }
                    if (!variableSpecifier.toString().isEmpty()) {
                        int precision = Integer.parseInt(variableSpecifier.toString());

                        DecimalFormat decimalFormat = new DecimalFormat("0." + "0".repeat(precision));
                        finalTextBuilder.append(decimalFormat.format(Float.parseFloat(input)));
                    } else {
                        DecimalFormat decimalFormat = new DecimalFormat("0.00");
                        finalTextBuilder.append(decimalFormat.format(Float.parseFloat(input)));
                    }
                }
            } else {
                finalTextBuilder.append(charTextArray[i]);
            }
        }
        System.out.println(finalTextBuilder.toString());
    }

    private static boolean containsLowerLetters(String input) {
        return input.matches(".*[a-z].*");
    }
    private static boolean containsUpperLetters(String input) {
        return input.matches(".*[A-Z].*");
    }
    private static boolean containsLetters(String input) {
        return input.matches(".*[a-zA-Z].*");
    }

    private static boolean containsOnlyDigits(String input) {
        return input.matches("\\d+");
    }

    private static boolean isValidFloat(String input) {
        try {
            Float.parseFloat(input);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }
    int strlen(char[] string)
    {
        int i = 0;
        while(string[i] != '\0')
        {
            i++;
        }
        return i;
    }
}
