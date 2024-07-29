#include <future>
template <typename F>
auto async_deferred(F &&func) -> std::future<decltype(func())> {
  using result_type = decltype(func());
  auto promise = std::promise<result_type>();
  auto future = promise.get_future();
  std::thread(std::bind(
                  [=](std::promise<result_type> &promise) {
                    try {
                      promise.set_value(func());
                      // Note: Will not work with std::promise<void>. Needs some
                      // meta-template programming which is out of scope for
                      // this example.
                    } catch (...) {
                      promise.set_exception(std::current_exception());
                    }
                  },
                  std::move(promise))).detach();
  return future;
}
