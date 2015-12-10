#include <ANetwork.hpp>
#ifdef _WIN32
# include <NetworkWin.hpp>
#else
# include <Network.hpp>
#endif
#include	<UnitTest.hpp>

int	main(int ac, char *argv[])
{
  UnitTest	unit;

  try {
    unit.init(ac, argv);
    unit.launch();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
