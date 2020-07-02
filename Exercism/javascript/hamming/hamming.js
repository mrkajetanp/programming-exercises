//
// This is only a SKELETON file for the 'Hamming' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const compute = (a, b) => {
  if (!a.length && b.length)
    throw Error("left strand must not be empty");

  if (!b.length && a.length)
    throw Error("right strand must not be empty");

  if (a.length != b.length)
    throw Error("left and right strands must be of equal length");

  let result = 0;

  for (let i = 0 ; i < a.length ; i++) {
    if (a[i] !== b[i])
      result++;
  }

  return result;
};
