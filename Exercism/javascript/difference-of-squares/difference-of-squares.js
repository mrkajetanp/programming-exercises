//
// This is only a SKELETON file for the 'Difference Of Squares' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export class Squares {
  constructor(x) {
    const arr = Array.from(Array(x+1).keys());
      this._squareOfSum = Math.pow(arr.reduce((sum, current) => sum + current, 0), 2);
      this._sumOfSquares = arr.reduce((sum, current) => sum + Math.pow(current, 2), 0);
      this._difference = this.squareOfSum - this.sumOfSquares;
  }

  get sumOfSquares() {
    return this._sumOfSquares;
  }

  get squareOfSum() {
    return this._squareOfSum;
  }

  get difference() {
    return this._difference;
  }
}
