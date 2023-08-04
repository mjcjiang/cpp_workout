#include <iostream>
#include <string>
#include <tuple>

enum class Status: std::uint32_t {
	     good = 0,
	     failed = 1,
	     incomplete = 100,
	     corrupt = 200,
	     audited = 500,
	     indeterminate = 0xFFFFFFFF
};

using UserInfo = std::tuple<std::string, std::string, std::size_t>;
enum class UserInfoFields {Name, Email, Reputation};

template<typename E>
constexpr auto
toUType(E enumerator) noexcept
{
  return
    static_cast<typename
		std::underlying_type_t<E>>(enumerator);
}

int main() {
  //enum Color: std::uint32_t;
  UserInfo user_info = std::make_tuple<std::string, std::string, std::size_t>("hjiang", "red", 10);
  auto name = std::get<toUType(UserInfoFields::Name)>(user_info);
  std::cout << name << std::endl;
  return 0;
}
