#include "../../source/array/array.h"
#include "../catch.hpp"
#include <array>

SCENARIO("array can be constructed",
	 "[construction][array]"){

  GIVEN("size greater then 0"){

    WHEN("default constructed"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,2>()) );
      }
    }

    WHEN("constucted with initializer list smaller then the array size"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,2>{1}) );
      }
    }

    WHEN("constucted with initializer list with the same size as the array"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,2>{1,2}) );
      }
    }

    WHEN("constucted with initializer list bigger then the array size"){
      THEN("it throws invalid_argument exception"){
	REQUIRE_THROWS_AS( (tc::array<int,2>{1,2,3}) , std::invalid_argument );
      }
    }
  }

  GIVEN("size equal to 0"){

    WHEN("default constructed"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,0>()) );
      }
    }

    WHEN("constucted with empty initializer list"){
      THEN("it constructs properly"){
	REQUIRE_NOTHROW( (tc::array<int,0>{}) );
      }
    }

    WHEN("constucted with non-empty initializer list"){
      THEN("it throws invalid_argument exception"){
	REQUIRE_THROWS_AS( (tc::array<int,0>{1}) , std::invalid_argument );
      }
    }
  }

}

SCENARIO("array size could be checked",
	 "[size][array]"){

  GIVEN("an array with size greater then 0"){
    tc::array<int,42> arr;

    WHEN("size is checked"){
      THEN("it returns the correct size"){
	REQUIRE(arr.size() == 42);
      }
    }

    WHEN("checked whether the array is empty"){
      THEN("it the result is flase"){
	REQUIRE_FALSE(arr.empty());
      }
    }
  }

  GIVEN("an array with size equal 0"){
    tc::array<int,0> arr;

    WHEN("size is checked"){
      THEN("it returns the correct size"){
	REQUIRE(arr.size() == 0);
      }
    }

    WHEN("checked whether the array is empty"){
      THEN("it the result is true"){
	REQUIRE(arr.empty());
      }
    }
  }
}
