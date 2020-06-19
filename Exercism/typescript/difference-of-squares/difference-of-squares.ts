export class Squares {

    public squareOfSum: number;
    public sumOfSquares: number;
    public difference: number;

    constructor(x: number) {
        const arr = Array.from(Array(x+1).keys());
        this.squareOfSum = Math.pow(arr.reduce((sum, current) => sum + current, 0), 2);
        this.sumOfSquares = arr.reduce((sum, current) => sum + Math.pow(current, 2), 0);
        this.difference = this.squareOfSum - this.sumOfSquares;
    }
}

export default Squares
