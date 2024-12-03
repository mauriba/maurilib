#ifndef MAURI_MATH_RANGE_HPP
#define MAURI_MATH_RANGE_HPP

namespace mauri {

class Range {
public:
  int start, stop, step;

  Range(int start, int end, int step = 1);
  Range(int end);

  Range begin() const;
  Range end() const;

  Range &operator++();
  Range &operator--();
  Range &operator+=(int n);
  Range &operator-=(int n);

  int operator*() const;
  bool operator==(const Range &other) const;
  bool operator!=(const Range &other) const;
};

} // namespace mauri

#endif
