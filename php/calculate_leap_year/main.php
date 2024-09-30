<?php
function isLeapYear(int $year) {
    $string_year = (string)$year;
    if (($year % 4 == 0 && $year % 100 != 0) || ($year % 400 == 0)) {
        $string_year.=" is a leap year";
    } else {
        $string_year.=" is not a leap year";
    }
    return $string_year;
}

echo "Enter a year: ";
$year = (int)readline();

echo isLeapYear($year) . PHP_EOL;
?>
