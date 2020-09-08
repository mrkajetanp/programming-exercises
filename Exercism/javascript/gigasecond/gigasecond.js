
export const gigasecond = (startDate) => {
  let result = new Date(startDate.getTime());
  result.setUTCSeconds(result.getUTCSeconds() + 1_000_000_000);
  return result;
};
