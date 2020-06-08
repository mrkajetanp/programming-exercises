function isLeapYear(year: number) {
    var factor = (x: number): boolean => year % x == 0;
    return factor(4) && (!factor(100) || factor(400));
}

export default isLeapYear
