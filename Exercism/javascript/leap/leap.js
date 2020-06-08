
export const isLeap = (year) => {
  let factor = (x) => year % x == 0;
  return factor(4) && (!factor(100) || factor(400));
};

