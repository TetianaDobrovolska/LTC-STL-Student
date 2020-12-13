#pragma once
#include <stdexcept>
#include <string>

struct Song
{
    std::string name;
    explicit Song(std::string song_name)
        : name {std::move(song_name)}
    {
    }
};

bool operator==(const Song& lhs, const Song& rhs)
{
    return lhs.name == rhs.name;
}

template<class Container>
class StaticPlaylist
{
public:
    /** @todo Member traits */
    using value_type = typename Container::value_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;
    using iterator = typename Container::iterator;
    using const_iterator = typename Container::const_iterator;
    using difference_type = typename Container::difference_type;
    using size_type = typename Container::size_type;

    /** @todo Iterators */
    const_iterator begin()
    {
        return m_tracklist.cbegin();
    }

    const_iterator end()
    {
        return m_tracklist.cend();
    }
    const_iterator cbegin()
    {
        return m_tracklist.cbegin();
    }

    const_iterator cend()
    {
        return m_tracklist.cend();
    }

    /** @todo Constructor from any reversible sequence container */
    template<class InputContainer>
    StaticPlaylist<Container>(const InputContainer& inputData)
        : m_tracklist(inputData.cbegin(), inputData.cend())
    { }

    /** @todo Assignment from any reversible sequence container */
    template<class InputContainer>
    StaticPlaylist<Container>& operator=(const InputContainer& inputData)
    {
        m_tracklist.assign(inputData.cbegin(), inputData.cend());
        return *this;
    }

    /** @todo Add track from initializer */
    template<class... Args>
    const Song& play(Args&&... songData)
    {
        return *m_tracklist.insert(begin(), Song{songData}...);
    }

    /** @todo Add track */
    const Song& play(const Song& song)
    {
        return *m_tracklist.insert(begin(), song);
    }

    /** @todo Get first track in playlist stack */
    const Song& current() const
    {
        if (!hasTracks())
        {
            throw std::out_of_range("");
        }
        return m_tracklist.front();
    }

    /** @todo Skip to the next track in playlist, remove current */
    void switchNext()
    {
        if (!hasTracks())
        {
            throw std::out_of_range("");
        }
        m_tracklist.erase(m_tracklist.begin());
    }

    /** @todo Amount of tracks in playlist */
    size_type count() const
    {
        return m_tracklist.size();
    }

    /** @todo Checks if playlist has any playable tracks */
    bool hasTracks() const
    {
        return !m_tracklist.empty();
    }

private:
    Container m_tracklist;
};
