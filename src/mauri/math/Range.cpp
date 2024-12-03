#include "Range.hpp"

namespace mauri {

Range::Range(int start, int end, int step)
    : start(start), stop(end), step(step) {}

Range::Range(int end) { Range(0, end); }

Range Range::begin() const { return Range(start, stop, step); }

Range Range::end() const {
  // Range is implicit (`stop` within range), so we calculate the next
  // iterator's step after `stop` for the end iterator.
  int explicit_stop = stop + (stop % step == 0 ? step : stop % step);
  return Range(explicit_stop, stop, step);
}

Range &Range::operator++() {
  start += step;
  return *this;
}

Range &Range::operator--() {
  start -= step;
  return *this;
}

Range &Range::operator+=(int n) {
  start += n;
  return *this;
}

Range &Range::operator-=(int n) {
  start -= n;
  return *this;
}

bool Range::operator==(const Range &other) const {
  return other.start == start && other.stop == stop && other.step == step;
}
int Range::operator*() const { return start; }
bool Range::operator!=(const Range &other) const { return !(other == *this); }

} // namespace mauri
