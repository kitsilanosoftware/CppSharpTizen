//
// Open Service Platform
// Copyright (c) 2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Apache License, Version 2.0 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//


/**
 * @file     FUixVisionImageFeatureManager.h
 * @brief    This is the header file for the %ImageFeatureManager class.
 *
 * This header file contains the declarations of the %ImageFeatureManager class.
 */

#ifndef _FUIX_VISION_IMAGE_FEATURE_MANAGER_H_
#define _FUIX_VISION_IMAGE_FEATURE_MANAGER_H_
#include <FBaseObject.h>
#include <FBase.h>
#include <FGrpBitmap.h>
#include <FUixVisionImageFeatureInfo.h>
#include <FMedia.h>

namespace Tizen { namespace Uix { namespace Vision
{

/**
 * @class    ImageFeatureManager
 * @brief    This class provides methods to generate individual feature data from an individual image data and collect to feature set file.
 *
 * @since    2.1
 *
 * The %ImageFeatureManager class provides methods to generate individual feature data from an individual image data. This class also provides methods to manage image feature set which is a collection of individual feature data.
 *
 * The following example demonstrates how to use the %ImageFeatureManager class.
 *
 * @code
 * 
 * #include <FBase.h>
 * #include <FUix.h>
 * #include <FGraphics.h>
 * #include <FIo.h>
 * #include <FMedia.h>
 *
 * using namespace Tizen::Base;
 * using namespace Tizen::Media;
 * using namespace Tizen::Graphics;
 * using namespace Tizen::Io;
 * using namespace Tizen::Uix::Vision;
 *
 * class MyClass
 * {
 *
 * public:
 * 	MyClass();
 * 	~MyClass();
 * 	result GenerateFeatureSet(void);
 *	result AddImageFeatureSet(void);
 * };
 *
 * result
 * MyClass::GenerateFeatureSet(void)
 * {
 *     result r;
 *     ImageFeatureManager imageFeatureManager;
 *     r = imageFeatureManager.Construct();
 *
 *     //Creates new feature sets
 *     imageFeatureManager.AddFeature("/opt/usr/media/Images/image1.jpg");
 *     imageFeatureManager.AddFeature("/opt/usr/media/Images/image2.jpg");
 *     imageFeatureManager.AddFeature("/opt/usr/media/Images/image3.jpg");
 *     r = imageFeatureManager.Flush(new String("/opt/usr/media/Images/testFeatureSet.xdb"));
 *
 *     return r;
 * }
 *
 * result
 * MyClass::AddImageFeatureSet()
 * {
 *     result r;
 *     ImageFeatureManager imageFeatureManager;
 *     imageFeatureManager.Construct();
 *     imageFeatureManager.Load("/opt/usr/media/Images/testFeatureSet.xdb");
 *     imageFeatureManager.AddFeature("/opt/usr/media/Images/image1.jpg");
 *     imageFeatureManager.AddFeature("/opt/usr/media/Images/image2.jpg");
 *     imageFeatureManager.AddFeature("/opt/usr/media/Images/image3.jpg");
 *     r = imageFeatureManager.Flush();
 *
 *     return r;
 * }
 * @endcode
 */
class _OSP_EXPORT_ ImageFeatureManager
    : public Tizen::Base::Object
{
public:

    /**
     * This is the default constructor for this class. @n
     * The object is not fully constructed after this constructor is called. @n
     * For full construction, the Construct() method must be called right after calling this constructor.
     *
     * @since    2.1
     */
    ImageFeatureManager(void);

    /**
     * This is the destructor for this class. @n
     * The resources are deallocated by this method.
     * This destructor overrides Tizen::Base::Object::~Object().
     *
     * @since    2.1
     */
    ~ImageFeatureManager(void);

    /**
     * Initializes this instance of %ImageFeatureManager and create image feature set. @n
     * Every application must call %Construct() before calling any other methods of %ImageFeatureManager.
     *
     * @since       2.1
     *
     * @feature     %http://tizen.org/feature/vision.image_recognition
     *
     * @return      An error code
     *
     * @exception   E_SUCCESS          The method is successful.
     * @exception   E_UNSUPPORTED_OPERATION   The Emulator or target device does not support the required feature. 
     * For more information, see <a href="../org.tizen.gettingstarted/html/tizen_overview/application_filtering.htm">Application Filtering</a>.
     * @remarks     Before calling this method, check whether the feature is supported by 
	 *			Tizen::System::SystemInfo::GetValue(const Tizen::Base::String&, bool&).
     */
    result Construct(void);

    /**
     * Loads a feature set file.
     *
     * @since       2.1
     *
     * @return      An error code
     *
     * @param[in]   featureSetFilePath       The feature set file path
     *
     * @exception   E_SUCCESS                The method is successful.
     * @exception   E_INVALID_ARG            The specified feature set file path is invalid.
     * @exception   E_OUT_OF_MEMORY          The memory is insufficient.
     *
     * @remarks     
     *              - If a feature set file exists, it is updated.
     *              - If a feature set file does not exist, it is newly created.
     *              - It is not mandatory to call this method to create new feature set file, but Flush() must be called with valid feature set file path.
     */
    result Load(const Tizen::Base::String& featureSetFilePath);

    /**
     * Gets a list of supported image file formats for adding a feature.
     *
     * @since       2.1
	 *
     * @return      A list of supported image file formats
     */
    static Tizen::Base::Collection::IListT<Tizen::Media::ImageFormat>* GetSupportedImageFileFormatsListN(void);

    /**
     * Adds a feature to a feature set.
     *
     * @since       2.1
     *
     * @return      A feature index of newly and successfully created feature, otherwise returns -1.
     *
     * @param[in]   imagePath            The input image file path
     *
     * @exception   E_INVALID_ARG        The specified input parameter is invalid.
     *
     * @remarks     
     *              - The specific error code can be accessed using the GetLastResult() method.
     *              - Input image file must be one of the supported image file formats.
     *              - Calling this method actually means 'Mark As Add Feature'.
     *              And the marked feature data will be added to a feature set file after calling Flush().
     * @see         GetSupportedImageFileFormatsListN()
     *              Flush(const Tizen::Base::String*)
     */
    int AddFeature(const Tizen::Base::String& imagePath);

    /**
     * Adds a feature to a feature set.
     *
     * @since       2.1
     *
     * @return      A feature index of newly and successfully created feature, otherwise returns -1.
     *
     * @param[in]   imageBuffer              The image buffer of grayscale image data of specified width and height
     * @param[in]   width                    The width of the input image
     * @param[in]   height                   The height of the input image
     * @param[in]   description              The description of the feature
     *
     * @exception   E_INVALID_ARG            A specified input parameter is invalid.
     *
     * @remarks     
     *              - The specific error code can be accessed using the GetLastResult() method.
     *              - Calling this method actually means 'Mark As Add Feature'.
     *              And the marked feature data will be added to a feature set file after calling Flush().
     * @see         Flush(const Tizen::Base::String*)
     */
    int AddFeature(const Tizen::Base::ByteBuffer& imageBuffer, int width, int height, const Tizen::Base::String& description);

    /**
     * Gets the total number of features in a feature set.
     *
     * @since       2.1
     *
     * @return      The total number of features in a feature set
     */
    int GetTotalNumberOfFeatures(void);

    /**
     * Deletes a feature with a specified index in a feature set.
     *
     * @since       2.1
     *
     * @return      An error code
     *
     * @param[in]   featureIndex             The feature index in a feature set
     *
     * @exception   E_SUCCESS                The method is successful.
     * @exception   E_INVALID_ARG            The specified input parameter is invalid.
     * @exception   E_OUT_OF_MEMORY          The memory is insufficient.
     *
     * @remarks     Calling this method actually means 'Mark As Delete Feature'.
     *              And the marked feature data is deleted after calling Flush().
     * @see         Flush(const Tizen::Base::String*)
     */
    result DeleteFeature(int featureIndex);

    /**
     * Deletes all features in a feature set.
     *
     * @since       2.1
     *
     * @return      An error code
     *
     * @exception   E_SUCCESS          The method is successful.
     * @exception   E_OUT_OF_MEMORY    The memory is insufficient.
     *
     * @remarks     Calling this method actually means 'Mark As Delete All Features'.
     *              And all feature data is deleted after calling Flush().
     * @see         Flush(const Tizen::Base::String*)
     */
    result DeleteAllFeatures(void);

    /**
     * Flushes features into a feature set file and updates all changes as marked.
     *
     *
     * @since       2.1
     *
     * @return      An error code
     *
     * @param[in]   featureSetFilePath   The feature set file path
     * @exception   E_SUCCESS            The method is successful.
     * @exception   E_INVALID_ARG        The specified feature set path is invalid.
     *
     * @remarks     
     *              - All changes in the feature set file by AddFeature() or DeleteFeature() or DeleteAllFeatures() are updated by calling this method.
     *              - If @c featureSetFilePath is not decided or is same as the file path used in Load(), the loaded feature set file is updated.
     *              - If @c featureSetFilePath is not same as the file path used in %Load(), the loaded feature set file remains as is and new feature set file is created.
     *              - If @c featureSetFilePath is @c null, the feature set file loaded by %Load() is overwritten.
     * 	 			- If @c featureSetFilePath is not decided or is same to file path used in %Load() and the loaded feature set file is read-only @c E_INVALID_ARG exception will be  returned.
     * 	 			- If %Load() is not called to create new feature set file, this method must be called with valid @c featureSetFilePath.
     *
     */
    result Flush(const Tizen::Base::String* featureSetFilePath = null);

    /**
     * Gets information of the individual feature.
     *
     * @since       2.1
     *
     * @return      A pointer to ImageFeatureInfo
     *
     * @param[in]   featureIndex       The feature index in a feature set
     */
    const Tizen::Uix::Vision::ImageFeatureInfo* GetImageFeatureInfo(int featureIndex) const;


private:
    /**
     * The implementation of this copy constructor is intentionally blank and declared as private to prohibit copying of objects.
     */
    ImageFeatureManager(const ImageFeatureManager&);

    /**
     * The implementation of this copy assignment operator is intentionally blank and declared as private to prohibit copying of objects.
     */
    ImageFeatureManager& operator=(const ImageFeatureManager&);

private:
    class _ImageFeatureManagerImpl* __pImageFeatureManagerImpl;
    friend class _ImageFeatureManagerImpl;
  };

} } } //Tizen::Uix::Vision

#endif // _FUIX_VISION_IMAGE_FEATURE_MANAGER_H_
